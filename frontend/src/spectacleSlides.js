import React from 'react';
import WithSpectacle from "./spectacle"

export default class SpectacleSlides extends React.Component {
  render() {
    return (
      <WithSpectacle
        render={({ Deck, MarkdownSlides, theme }) =>
          <Deck theme={theme}>
            {MarkdownSlides(this.props.markdown).slice(1)}
          </Deck>
        }
      />
    );
  }
}
