#include <QDesktopServices>
#include <QFileDialog>
#include <QStandardPaths>
#include <QWebEngineHistory>
#include <QWebEngineHistoryItem>
#include <messenger/app-info.hpp>
#include <messenger/ui/popup_page.hpp>
#include <messenger/ui/webengine_page.hpp>

bool messenger::webengine_page::openurl_helper(const QUrl &url) const {
  QDesktopServices::openUrl(url);

  return false;
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
      return openurl_helper(url);
    }
  }
}

QWebEnginePage *
messenger::webengine_page::createWindow(QWebEnginePage::WebWindowType type) {
  if(type == QWebEnginePage::WebWindowType::WebBrowserTab) {
    return new messenger::popup_page(profile());
  } else {
    return nullptr;
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
    messenger::webengine_profile *_profile)
    : QWebEnginePage(_profile) {}

messenger::webengine_page::~webengine_page() { profile()->deleteLater(); }