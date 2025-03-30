#ifndef WEBENGINE_PAGE_H
#define WEBENGINE_PAGE_H

#include <QWebEnginePage>
#include <messenger/ui/webengine_profile.hpp>

namespace messenger {
class webengine_page : public QWebEnginePage {
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
  bool acceptNavigationRequest(const QUrl &url,
                               QWebEnginePage::NavigationType type,
                               bool isMainFrame) override;
  QWebEnginePage *createWindow(QWebEnginePage::WebWindowType type) override;
  QStringList chooseFiles(QWebEnginePage::FileSelectionMode mode,
                          const QStringList &oldFiles,
                          const QStringList &acceptedMimeTypes) override;

public:
  webengine_page(messenger::webengine_profile *_profile,
                 QWidget *const _parent = nullptr);
  ~webengine_page();
};
} // namespace messenger

#endif
