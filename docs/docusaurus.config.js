module.exports = {
  title: 'Shunya Interfaces',
  tagline: 'Simple and Low Code library to build IoT applications',
  url: 'https://shunyaos.github.io',
  baseUrl: '/shunyainterfaces/',
  favicon: 'img/favicon.ico',
  organizationName: 'shunyaos', // Usually your GitHub org/user name.
  projectName: 'shunyainterfaces', // Usually your repo name.
  themeConfig: {
    navbar: {
      title: 'Shunya Interfaces',
      logo: {
        alt: 'IoTIoT-logo',
        src: 'img/logo.png',
      },
      links: [
        {to: 'docs/get-started/first-app', label: 'Get Started', position: 'right'},
        {to: 'docs/demos/farm-demo', label: 'Demo', position: 'right'},
        {
          href: 'https://github.com/shunyaos/shunyainterfaces',
          label: 'GitHub',
          position: 'right',
        },
      ],
    },
    footer: {
      style: 'dark',
      links: [
        {
          title: 'Docs',
          items: [
            {
              label: 'Getting Started',
              to: 'docs/get-started/first-app',
            },
            {
              label: 'Build solutions',
              to: 'docs/build-solutions/01-intro',
            },
          ],
        },
        {
          title: 'Community',
          items: [
            {
              label: 'Stack Overflow',
              href: 'https://stackoverflow.com/questions/tagged/shunyainterfaces',
            },
          ],
        },
        {
          title: 'Social',
          items: [
            {
              label: 'GitHub',
              href: 'https://github.com/shunyaos/shunyainterfaces',
            },
          ],
        },
      ],
      copyright: `Copyright © ${new Date().getFullYear()} Shunya OS, Inc.`,
    },
  },
  presets: [
    [
      '@docusaurus/preset-classic',
      {
        docs: {
          sidebarPath: require.resolve('./sidebars.js'),
          editUrl:
            'https://github.com/shunyaos/shunyainterfaces/edit/release-2.0/docs/',
        },
        theme: {
          customCss: require.resolve('./src/css/custom.css'),
        },
      },
    ],
  ],
};
