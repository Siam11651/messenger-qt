#include <QDesktopServices>
#include <QStandardPaths>
#include <QWebEngineHistory>
#include <QWebEngineHistoryItem>
#include <messenger/app-info.hpp>
#include <messenger/ui/popup_page.hpp>
#include <messenger/ui/webengine_page.hpp>

QWebEngineProfile *
messenger::webengine_page::create_profile(const QString &_profile_name) const {
  QWebEngineProfile *new_profile = new QWebEngineProfile(_profile_name);

  new_profile->setPersistentCookiesPolicy(
      QWebEngineProfile::PersistentCookiesPolicy::AllowPersistentCookies);
  new_profile->setPersistentStoragePath(
      QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) +
      "/webview-data");

  return new_profile;
}

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
  return new messenger::popup_page(profile());
}

messenger::webengine_page::webengine_page(const QString &_profile_name)
    : QWebEnginePage(create_profile(_profile_name)) {}

messenger::webengine_page::~webengine_page() { delete profile(); }