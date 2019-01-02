const base = {
  name: 'StackSmithStudio',
  url: 'https://stacksmithstudio.com'
};

const config = {
  /* meta tags */
  siteTitle: `${base.name}`,
  siteTitlePostfix: ` - ${base.name}`,
  siteDescription: `${
    base.name
    }`,
  siteImage: 'preview.jpg',
  siteLanguage: 'en',

  /* site header */
  headerTitle: `${base.name}`,
  headerSubTitle: 'a series of starters for GatsbyJS',

  /* url */
  siteUrl: base.url
  // pathPrefix: '',
};

module.exports = config;
