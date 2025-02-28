#include <QStandardPaths>
#include <messenger/ui/webengine_profile.hpp>

messenger::webengine_profile::webengine_profile(const QString &_name)
    : QWebEngineProfile(_name) {
  setPersistentCookiesPolicy(
      QWebEngineProfile::PersistentCookiesPolicy::AllowPersistentCookies);
  setPersistentStoragePath(
      QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) +
      "/webview-data");
}

messenger::webengine_profile::~webengine_profile() {}