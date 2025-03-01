#include <messenger/ui/webengine_page.hpp>
#include <messenger/ui/webengine_view.hpp>

messenger::webengine_view::webengine_view(const QString &_profile_name)
    : QWebEngineView() {
  m_webengine_profile = new messenger::webengine_profile(_profile_name);
  setPage(new messenger::webengine_page(m_webengine_profile));
}

messenger::webengine_profile *messenger::webengine_view::profile() const {
  return m_webengine_profile;
}

messenger::webengine_view::~webengine_view() {
  page()->deleteLater();
  m_webengine_profile->deleteLater();
}