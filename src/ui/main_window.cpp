#include <QStandardPaths>
#include <QUrl>
#include <QWebEngineProfile>
#include <messenger/ui/main_windows.hpp>
#include <messenger/app-info.hpp>

messenger::main_window::main_window() : QMainWindow() {
  setMinimumWidth(800);
  setMinimumHeight(600);
  setWindowTitle("Messenger Qt");

  m_webview_profile = new QWebEngineProfile(messenger::app_id);

  m_webview_profile->setPersistentCookiesPolicy(QWebEngineProfile::PersistentCookiesPolicy::AllowPersistentCookies);
  m_webview_profile->setPersistentStoragePath(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/webview-data");

  m_webview = new QWebEngineView(m_webview_profile);

  setCentralWidget(m_webview);
  m_webview->load(QUrl("https://www.messenger.com"));
}

messenger::main_window::~main_window() {
  delete m_webview;
  delete m_webview_profile;
}