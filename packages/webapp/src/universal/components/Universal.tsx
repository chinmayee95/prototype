import { compose } from 'redux';
import styled, { createGlobalStyle } from 'styled-components';
import React from 'react';

import App from '@@src/universal/components/App/App';
import color from '@@src/universal/styles/color';
import ErrorBoundary from '@@src/universal/components/Error/ErrorBoundary';
import normalize from '@@src/universal/styles/normalize';
import { w320 } from '@@src/universal/styles/media';

const Normalize = createGlobalStyle`
  ${normalize}
`;

const GlobalStyle = createGlobalStyle({
  '*': {
    boxSizing: 'border-box',
  },
  a: {
    '&:hover': {
      textDecoration: 'none',
    },
    color: 'inherit',
    cursor: 'pointer',
    textDecoration: 'none',
    transition: 'color 0.5s ease, border-bottom 0.5s ease',
  },
  body: {
  },
  button: {
    backgroundColor: 'inherit',
    border: 'none',
    color: 'inherit',
    cursor: 'pointer',
    margin: 0,
    outline: 'none',
    padding: 0,
  },
  html: {
    backgroundColor: color.htmlBackgroundColor,
    color: color.htmlColor,
    fontFamily: '"Source Serif Pro", "Work Sans", "Helvetica", "Arial", sans-serif;',
    fontSize: 14,
    lineHeight: 1.51,
  },
  input: {
    border: 'none',
    outline: 'none',
  },
  p: {
    margin: 0,
  },
  ul: {
    listStyleType: 'none',
    margin: 0,
    padding: 0,
  },
});

const StyledUniversal = styled.div({
  display: 'flex',
  fontSize: '1.34rem',
  justifyContent: 'center',
  minWidth: 318,
  ...w320({
    fontSize: '1.25rem',
  }),
});

const Universal: React.FC<any> = () => {
  return (
    <ErrorBoundary>
      <StyledUniversal>
        <Normalize />
        <GlobalStyle />
        <App />
      </StyledUniversal>
    </ErrorBoundary>
  );
};

export default compose(
)(Universal);

declare global {
  interface Window {
    SimpleMDE;
  }
}
