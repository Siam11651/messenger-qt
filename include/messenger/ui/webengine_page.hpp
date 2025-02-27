#ifndef WEBENGINE_PAGE_H
#define WEBENGINE_PAGE_H

#include <QWebEnginePage>
#include <QWebEngineProfile>

namespace messenger {
class webengine_page : public QWebEnginePage {
  private:
  QWebEngineProfile *create_profile(const QString &_profile_name) const;

  protected:
  bool acceptNavigationRequest(const QUrl &url, QWebEnginePage::NavigationType type, bool isMainFrame) override;

  public:
  webengine_page(const QString &_profile_name);
  ~webengine_page();
};
} // namespace messenger

#endif