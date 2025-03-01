#include <QWebEngineView>
#include <messenger/ui/menu/filemenu.hpp>
#include <messenger/ui/main_window.hpp>
#include <messenger/ui/window/downloads_window.hpp>
#include <messenger/app-info.hpp>

void messenger::filemenu::handle_refresh_trigger() {
  QWebEngineView *const webengine_view = messenger::main_window::webengine_view;

  if(webengine_view != nullptr) {
    webengine_view->reload();
  }
}

void messenger::filemenu::handle_restart_trigger() {
  QWebEngineView *const webengine_view = messenger::main_window::webengine_view;

  if(webengine_view != nullptr) {
    webengine_view->load(QUrl(messenger::https_domain.c_str()));
  }
}

void messenger::filemenu::handle_downloads_trigger() {
  (new messenger::downloads_window())->show();
}

void messenger::filemenu::handle_quit_trigger() {
  
}

messenger::filemenu::filemenu() : QMenu() {
  setTitle("File");

  m_refresh_action = new QAction("Refresh");
  m_restart_action = new QAction("Restart");
  m_downloads_action = new QAction("Downloads");
  m_quit_action = new QAction("Quit");

  addAction(m_refresh_action);
  addAction(m_restart_action);
  addSeparator();
  addAction(m_downloads_action);
  addSeparator();
  addAction(m_quit_action);
  connect(m_refresh_action, &QAction::triggered, this, &messenger::filemenu::handle_refresh_trigger);
  connect(m_restart_action, &QAction::triggered, this, &messenger::filemenu::handle_restart_trigger);
  connect(m_downloads_action, &QAction::triggered, this, &messenger::filemenu::handle_downloads_trigger);
  connect(m_quit_action, &QAction::triggered, this, &messenger::filemenu::handle_quit_trigger);
}

messenger::filemenu::~filemenu() {
  m_refresh_action->deleteLater();
  m_restart_action->deleteLater();
  m_downloads_action->deleteLater();
  m_quit_action->deleteLater();
}