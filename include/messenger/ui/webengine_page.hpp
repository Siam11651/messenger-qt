#ifndef WEBENGINE_PAGE_H
#define WEBENGINE_PAGE_H

#include <QWebEnginePage>
#include <QWebEngineProfile>

namespace messenger {
class webengine_page : public QWebEnginePage {
private:
  QWebEngineProfile *create_profile(const QString &_profile_name) const;
  bool openurl_helper(const QUrl &url) const;

protected:
  bool acceptNavigationRequest(const QUrl &url,
                               QWebEnginePage::NavigationType type,
                               bool isMainFrame) override;
  QWebEnginePage *createWindow(QWebEnginePage::WebWindowType type) override;
  QStringList chooseFiles(QWebEnginePage::FileSelectionMode mode, const QStringList &oldFiles, const QStringList &acceptedMimeTypes) override;

public:
  webengine_page(const QString &_profile_name);
  ~webengine_page();
};
} // namespace messenger

#endif