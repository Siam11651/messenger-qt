#include <messenger/ui/webengine_page.hpp>
#include <messenger/ui/webengine_view.hpp>

messenger::webengine_view::webengine_view(const QString &_profile_name)
    : QWebEngineView() {
  messenger::webengine_profile *m_webengine_profile =
      new messenger::webengine_profile(_profile_name, this);

  setPage(new messenger::webengine_page(m_webengine_profile, this));
}

messenger::webengine_profile *messenger::webengine_view::profile() const {
  return (messenger::webengine_profile *)page()->profile();
}

messenger::webengine_view::~webengine_view() {}