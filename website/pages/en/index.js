/**
 * Copyright (c) 2017-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

const React = require('react');

const CompLibrary = require('../../core/CompLibrary.js');

const MarkdownBlock = CompLibrary.MarkdownBlock; /* Used to read markdown */
const Container = CompLibrary.Container;
const GridBlock = CompLibrary.GridBlock;

class HomeSplash extends React.Component {
  render() {
    const {siteConfig, language = ''} = this.props;
    const {baseUrl, docsUrl} = siteConfig;
    const docsPart = `${docsUrl ? `${docsUrl}/` : ''}`;
    const langPart = `${language ? `${language}/` : ''}`;
    const docUrl = doc => `${baseUrl}${docsPart}${langPart}${doc}`;

    const SplashContainer = props => (
      <div className="homeContainer">
        <div className="homeSplashFade">
          <div className="wrapper homeWrapper">{props.children}</div>
        </div>
      </div>
    );

    const Logo = props => (
      <div className="projectLogo">
        <img align="right" src={props.img_src} alt="Project Logo" />
      </div>
    );

    const ProjectTitle = () => (
      <h2 className="projectTitle">
        {siteConfig.title}{' '}
        <small>{siteConfig.tagline}</small>
      </h2>
    );

    const PromoSection = props => (
      <div className="section promoSection">
        <div className="promoRow">
          <div className="pluginRowBlock">{props.children}</div>
        </div>
      </div>
    );

    const Button = props => (
      <div className="pluginWrapper buttonWrapper">
        <a className="button" href={props.href} target={props.target}>
          {props.children}
        </a>
      </div>
    );

    return (
      <SplashContainer>
        <div className="index-hero-inner">
          <ProjectTitle siteConfig={siteConfig} />
          <PromoSection>
				 	  <div className="index-ctas">
							<a
								className="button index-ctas-get-started-button"
								href={docUrl('installation.html')}>
								Get Started
							</a>
						</div>
          </PromoSection>
        </div>
      </SplashContainer>
    );
  }
}

class Index extends React.Component {
  render() {
    const {config: siteConfig, language = ''} = this.props;
    const {baseUrl} = siteConfig;

    const Block = props => (
      <Container
        padding={['bottom', 'top']}
        id={props.id}
        background={props.background}>
        <GridBlock
          align="center"
          contents={props.children}
          layout={props.layout}
        />
      </Container>
    );

    const FeatureCallout = () => (
      <div
        className="productShowcaseSection paddingBottom"
        style={{textAlign: 'center'}}>
        <h2>Feature Callout</h2>
        <MarkdownBlock>These are features of this project</MarkdownBlock>
      </div>
    );

    const Description = () => (
      <Block background="light">
        {[
          {
            content:
              'Create your own IoT apps without having to worry about embedded development.' +
	      '**[Try out!](docs/water-meter)**',
            image: `${baseUrl}img/undraw_statistics_ctoq.svg`,
            imageAlign: 'right',
            title: 'Get Started within minutes',
          },
        ]}
      </Block>
    );


    const LearnHow = () => (
      <Block background="light">
        {[
          {
            content:
              'We currently support 30 different sensors and we are constantly adding support to more.',
            image: `${baseUrl}img/undraw_in_progress_ql66.svg`,
            imageAlign: 'left',
            title: 'Support over 30 sensors',
          },
        ]}
      </Block>
    );

    const TryOut = () => (
      <Block id="try">
        {[
          {
            content:
              'While we get to Focus on Embedded. We know Embedded and we want users to Focus on Business logic and let us handle all embedded development for you.',
            image: `${baseUrl}img/undraw_designer_mindset_7fhu.svg`,
            imageAlign: 'right',
            title: 'You get to Focus on Creation!',
          },
        ]}
      </Block>
    );

    const Thirdparty = () => (
      <Block background="light">
        {[
          {
            content:
              'Visualize data, Send Alerts and do more with support to 3rd party Integrations like grafana, Twilio etc.' +
	      '**[Try out!](docs/water-meter)**',
            image: `${baseUrl}img/undraw_personal_goals_edgd.svg`,
            imageAlign: 'left',
            title: 'Support to 3rd party Integrations',
          },
        ]}
      </Block>
    );

    const Features = () => (
      <Block layout="fourColumn" background="light">
        {[
          {
            content: 'Do more with Less code.',
            image: `${baseUrl}img/undraw_react.svg`,
            imageAlign: 'top',
            title: 'Low Code Library',
          },
          {
            content: 'Small Footprint and Fast code execution.',
            image: `${baseUrl}img/undraw_stars.svg`,
            imageAlign: 'top',
            title: 'Built with C/C++',
          },
          {
            content: 'Create IoT products with ease.',
            image: `${baseUrl}img/undraw_operating_system.svg`,
            imageAlign: 'top',
            title: 'JS/Python Developer friendly APIs',
          },

        ]}
      </Block>
    );

    const Showcase = () => {
      if ((siteConfig.users || []).length === 0) {
        return null;
      }

      const showcase = siteConfig.users
        .filter(user => user.pinned)
        .map(user => (
          <a href={user.infoLink} key={user.infoLink}>
            <img src={user.image} alt={user.caption} title={user.caption} />
          </a>
        ));

      const pageUrl = page => baseUrl + (language ? `${language}/` : '') + page;

      return (
        <div className="productShowcaseSection paddingBottom">
          <h2>Who is Using This?</h2>
          <p>This project is used by all these people</p>
          <div className="logos">{showcase}</div>
          <div className="more-users">
            <a className="button" href={pageUrl('users.html')}>
              More {siteConfig.title} Users
            </a>
          </div>
        </div>
      );
    };

    return (
      <div>
        <HomeSplash siteConfig={siteConfig} language={language} />
        <div className="mainContainer">
          <Features />
          <Description />
          <LearnHow />
          <TryOut />
	  <Thirdparty />
          <Showcase />
        </div>
      </div>
    );
  }
}

module.exports = Index;
