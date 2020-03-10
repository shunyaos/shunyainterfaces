import React from 'react';
import classnames from 'classnames';
import Layout from '@theme/Layout';
import Link from '@docusaurus/Link';
import useDocusaurusContext from '@docusaurus/useDocusaurusContext';
import useBaseUrl from '@docusaurus/useBaseUrl';
import styles from './styles.module.css';

const features = [
  {
    title: <>Simplified API's</>,
    imageUrl: 'img/undraw_code_typing_7jnv.svg',
    description: (
      <>
				Create a full stack IoT Application within 5 lines of code. 
      </>
    ),
  },
  {
    title: <>Written in C</>,
    imageUrl: 'img/c.png',
    description: (
      <>
				Wrtitten in C allows Shunya Interfaces to gather data fast, while footprint remains low. 
      </>
    ),
  },
  {
    title: <>Support to 3rd Party Apps</>,
    imageUrl: 'img/undraw_dashboard_nklg.svg',
    description: (
      <>
				Send Alerts, View Dashboards, Arrange Data and Apply Machine Learning with 3rd Party Apps. 
      </>
    ),
  },
];

function Feature({imageUrl, title, description}) {
  const imgUrl = useBaseUrl(imageUrl);
  return (
    <div className={classnames('col col--4', styles.feature)}>
      {imgUrl && (
        <div className="text--center">
          <img className={styles.featureImage} src={imgUrl} alt={title} />
        </div>
      )}
      <h3>{title}</h3>
      <p>{description}</p>
    </div>
  );
}

const demos = [
  {
    title: <>IoT devices for Farms</>,
    imageUrl: 'img/undraw_environment_iaus.svg',
    description: (
      <>
				Monitor critical enviornmental parameters like temperature, pressure, humidity using Shunya Interfaces and Send them to cloud. 
      </>
    ),
  },
  {
    title: <>Smart Factories</>,
    imageUrl: 'img/undraw_factory_dy0a.svg',
    description: (
      <>
				Gather data from existing PLC, Meters and Sensors and turn them to Dashboards. 
      </>
    ),
  },
  {
    title: <>Remote Monitor Warehouses</>,
    imageUrl: 'img/undraw_financial_data_es63.svg',
    description: (
      <>
				Build Dataloggers which help monitor parameters, Notify stakeholders remotely. 
      </>
    ),
  },
];

function Demo({imageUrl, title, description}) {
  const imgUrl = useBaseUrl(imageUrl);
  return (
    <div className={classnames('col col--4', styles.demos)}>
      {imgUrl && (
        <div className="text--center">
          <img className={styles.demoImage} src={imgUrl} alt={title} />
        </div>
      )}
			<div className="text--center">
      <h1>{title}</h1>
      <p>{description}</p>
			</div>
    </div>
  );
}

function Home() {
  const context = useDocusaurusContext();
  const {siteConfig = {}} = context;
  return (
    <Layout
      title={`${siteConfig.title}`}
      description="Simple Low code library to build IoT Applications">
      <header className={classnames('hero hero--primary-dark', styles.heroBanner)}>
        <div className="container">
          <h1 className="hero__title">{siteConfig.title}</h1>
          <p className="hero__subtitle">{siteConfig.tagline}</p>
          <div className={styles.buttons}>
            <Link
              className={classnames(
                'button button--outline button--secondary button--lg',
                styles.indexCtasGetStartedButton,
              )}
              to={useBaseUrl('docs/demos/farm-demo')}>
              See Demo
            </Link>
          </div>
        </div>
      </header>
      <main>
        {demos && demos.length && (
          <section className={styles.demos}>
            <div className="container">
							<h1>Build</h1>
              <div className="row">
                {demos.map((props, idx) => (
                  <Demo key={idx} {...props} />
                ))}
              </div>
            </div>
          </section>
        )}
        {features && features.length && (
          <section className={styles.features}>
            <div className="container">
						<h1>Why?</h1>
              <div className="row">
                {features.map((props, idx) => (
                  <Feature key={idx} {...props} />
                ))}
              </div>
            </div>
          </section>
        )}
      </main>
    </Layout>
  );
}

export default Home;
