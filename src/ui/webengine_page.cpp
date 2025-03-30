#include <QDesktopServices>
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardPaths>
#include <QWebEngineHistory>
#include <QWebEngineHistoryItem>
#include <messenger/app-info.hpp>
#include <messenger/ui/dialog_page.hpp>
#include <messenger/ui/dialog_window.hpp>
#include <messenger/ui/popup_page.hpp>
#include <messenger/ui/webengine_page.hpp>

void messenger::webengine_page::handle_permission_request(
    QWebEnginePermission permission) {
  if (url().host().endsWith((messenger::domain.c_str()))) {
    const QWebEnginePermission::PermissionType permission_type =
        permission.permissionType();

    if (m_permission_message.find(permission_type) !=
        m_permission_message.end()) {
      const QMessageBox::StandardButton reply = QMessageBox::question(
          nullptr, "Confirm Permission", m_permission_message[permission_type],
          QMessageBox::StandardButton::Yes | QMessageBox::StandardButton::No);

      if (reply == QMessageBox::StandardButton::Yes) {
        permission.grant();
      } else if (reply == QMessageBox::StandardButton::Yes) {
        permission.deny();
      }
    }
  }
}

bool messenger::webengine_page::acceptNavigationRequest(
    const QUrl &url, QWebEnginePage::NavigationType type, bool isMainFrame) {
  if (!isMainFrame) {
    return true;
  }

  if (url.host().endsWith(messenger::domain.c_str())) {
    return true;
  } else {
    if (url.host().endsWith("facebook.com")) {
      return true;
    } else {
      QDesktopServices::openUrl(url);

      return false;
    }
  }
}

QWebEnginePage *
messenger::webengine_page::createWindow(QWebEnginePage::WebWindowType type) {
  if (type == QWebEnginePage::WebWindowType::WebBrowserTab) {
    return new messenger::popup_page(profile());
  } else {
    messenger::dialog_page *const new_page =
        new messenger::dialog_page((messenger::webengine_profile *)profile());
    messenger::dialog_window *const new_window =
        new messenger::dialog_window(new_page, (QWidget *)parent());

    new_window->show();

    return new_page;
  }
}

QStringList
messenger::webengine_page::chooseFiles(QWebEnginePage::FileSelectionMode mode,
                                       const QStringList &oldFiles,
                                       const QStringList &acceptedMimeTypes) {
  QFileDialog file_dialog;

  file_dialog.setMimeTypeFilters(acceptedMimeTypes);

  switch (mode) {
  case QWebEnginePage::FileSelectionMode::FileSelectOpen:
    file_dialog.setFileMode(QFileDialog::FileMode::ExistingFile);

    break;
  case QWebEnginePage::FileSelectionMode::FileSelectOpenMultiple:
    file_dialog.setFileMode(QFileDialog::FileMode::ExistingFiles);

    break;
  case QWebEnginePage::FileSelectionMode::FileSelectUploadFolder:
    file_dialog.setFileMode(QFileDialog::FileMode::Directory);

    break;
  default:
    file_dialog.setFileMode(QFileDialog::FileMode::AnyFile);
  }

  const int32_t status = file_dialog.exec();

  if (status == QDialog::DialogCode::Accepted) {
    QStringList to_return = oldFiles;
    const QStringList new_files = file_dialog.selectedFiles();

    for (const QString &filename : new_files) {
      to_return.push_back(filename);
    }

    return to_return;
  } else {
    return {};
  }
}

messenger::webengine_page::webengine_page(
    messenger::webengine_profile *_profile, QWidget *const _parent)
    : QWebEnginePage(_profile, _parent) {
  connect(this, &messenger::webengine_page::permissionRequested, this,
          &messenger::webengine_page::handle_permission_request);
}

messenger::webengine_page::~webengine_page() {}
