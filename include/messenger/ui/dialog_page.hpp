#ifndef DIALOG_PAGE_H
#define DIALOG_PAGE_H

#include <QWebEnginePage>
#include <messenger/ui/webengine_profile.hpp>

namespace messenger {
class dialog_page : public QWebEnginePage {
private:
  const QMap<QWebEnginePermission::PermissionType, QString>
      m_permission_message{
          {QWebEnginePermission::PermissionType::Notifications,
           "Allow sending notifications?"},
          {QWebEnginePermission::PermissionType::MediaVideoCapture,
           "Allow camera access?"},
          {QWebEnginePermission::PermissionType::MediaAudioCapture,
           "Allow mic access?"},
          {QWebEnginePermission::PermissionType::MediaAudioVideoCapture,
           "Allow camera and mic access?"},
          {QWebEnginePermission::PermissionType::DesktopVideoCapture,
           "Allow screen recording access?"},
          {QWebEnginePermission::PermissionType::DesktopAudioVideoCapture,
           "Allow screen recording and audio capture access?"}};

  void handle_permission_request(QWebEnginePermission permission);

public:
  dialog_page(messenger::webengine_profile *_profile,
              QWidget *const _parent = nullptr);
  ~dialog_page();
};
}; // namespace messenger

#endif