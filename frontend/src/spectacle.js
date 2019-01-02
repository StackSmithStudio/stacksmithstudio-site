import React from "react";
const spectacleExports = [ "Anim", "Appear", "BlockQuote", "Cite", "CodePane", "Code", "ComponentPlayground", "Deck", "Fill", "Fit", "Heading", "Image", "GoToAction", "Layout", "Link", "ListItem", "List", "Magic", "Markdown", "MarkdownSlides", "Notes", "Quote", "S", "Slide", "SlideSet", "TableBody", "TableHeader", "TableHeaderItem", "TableItem", "TableRow", "Table", "Text", "Typeface", "themes" ];

const setToFalse = (state, key) => ({ ...state, [key]: false });
const setTo = spectacle => (state, key) => ({
  ...state,
  [key]: spectacle[key]
});
const isReady = o => Object.values(o).every(x => !!x);

export default class WithSpectacle extends React.Component {
  constructor(props) {
    super(props);

    this.state = spectacleExports.reduce(setToFalse, {});
  }
  componentDidMount() {
    const spectacle = require("spectacle");
    const createTheme = require("spectacle-theme-nova/bundle").default;
    let theme = createTheme();

    this.setState(spectacleExports.reduce(setTo(spectacle), {theme}));
  }
  render() {
    if (!isReady(this.state)) return null;
    return this.props.render(this.state);
  }
}
