#ifndef WEBENGINE_PAGE_H
#define WEBENGINE_PAGE_H

#include <QWebEnginePage>
#include <messenger/ui/webengine_profile.hpp>

namespace messenger {
class webengine_page : public QWebEnginePage {
private:
  void handle_permission_request(QWebEnginePermission permission);
  bool acceptNavigationRequest(const QUrl &url,
                               QWebEnginePage::NavigationType type,
                               bool isMainFrame) override;
  QWebEnginePage *createWindow(QWebEnginePage::WebWindowType type) override;
  QStringList chooseFiles(QWebEnginePage::FileSelectionMode mode, const QStringList &oldFiles, const QStringList &acceptedMimeTypes) override;

public:
  webengine_page(messenger::webengine_profile *_profile, QWidget *const _parent = nullptr);
  ~webengine_page();
};
} // namespace messenger

#endif