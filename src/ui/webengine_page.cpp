#include <QStandardPaths>
#include <QDesktopServices>
#include <QWebEngineHistory>
#include <QWebEngineHistoryItem>
#include <iostream>
#include <messenger/ui/webengine_page.hpp>
#include <messenger/app-info.hpp>
#include <qdesktopservices.h>

QWebEngineProfile *messenger::webengine_page::create_profile(const QString &_profile_name) const {
  QWebEngineProfile *new_profile = new QWebEngineProfile(_profile_name);

  new_profile->setPersistentCookiesPolicy(QWebEngineProfile::PersistentCookiesPolicy::AllowPersistentCookies);
  new_profile->setPersistentStoragePath(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/webview-data");

  return new_profile;
}

bool messenger::webengine_page::openurl_helper(const QUrl &url) const {
  QDesktopServices::openUrl(url);

  return false;
}

bool messenger::webengine_page::acceptNavigationRequest(const QUrl &url, QWebEnginePage::NavigationType type, bool isMainFrame) {
  if(!isMainFrame) {
    return true;
  }

  if(url.host().endsWith(messenger::domain.c_str())) {
    return true;
  } else {
    if(url.host().endsWith("facebook.com")) {
      return true;
    } else {
      return openurl_helper(url);
    }
  }
}

messenger::webengine_page::webengine_page(const QString &_profile_name) : QWebEnginePage(create_profile(_profile_name)) {
  
}

messenger::webengine_page::~webengine_page() {
  delete profile();
}