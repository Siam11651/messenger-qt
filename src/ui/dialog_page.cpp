#include <QMessageBox>
#include <QWidget>
#include <messenger/app-info.hpp>
#include <messenger/ui/dialog_page.hpp>

void messenger::dialog_page::handle_permission_request(
    QWebEnginePermission permission) {
  if (url().host().endsWith((messenger::domain.c_str()))) {
    const QWebEnginePermission::PermissionType permission_type = permission.permissionType();

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

messenger::dialog_page::dialog_page(messenger::webengine_profile *_profile,
                                    QWidget *const _parent)
    : QWebEnginePage(_profile, _parent) {
  connect(this, &messenger::dialog_page::permissionRequested, this,
          &messenger::dialog_page::handle_permission_request);
}

messenger::dialog_page::~dialog_page() {}
