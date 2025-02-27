#include <QStandardPaths>
#include <messenger/ui/webengine_page.hpp>

QWebEngineProfile *messenger::webengine_page::create_profile(const QString &_profile_name) const {
  QWebEngineProfile *new_profile = new QWebEngineProfile(_profile_name);

  new_profile->setPersistentCookiesPolicy(QWebEngineProfile::PersistentCookiesPolicy::AllowPersistentCookies);
  new_profile->setPersistentStoragePath(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/webview-data");

  return new_profile;
}

bool messenger::webengine_page::acceptNavigationRequest(const QUrl &url, QWebEnginePage::NavigationType type, bool isMainFrame) {
  return true;
}

messenger::webengine_page::webengine_page(const QString &_profile_name) : QWebEnginePage(create_profile(_profile_name)) {
  
}

messenger::webengine_page::~webengine_page() {
  delete profile();
}