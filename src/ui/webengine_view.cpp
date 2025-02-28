#include <messenger/ui/webengine_view.hpp>
#include <messenger/ui/webengine_page.hpp>

messenger::webengine_view::webengine_view(const QString &_profile_name) : QWebEngineView(new webengine_page(_profile_name)) {

}

messenger::webengine_view::~webengine_view () {
  emit page()->windowCloseRequested();

  delete page();
}