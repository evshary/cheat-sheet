# SPHINX

SPINX is a tool to generate documentation easily.

Input is RST(reStructuredText) and output formats include HTML, PDF...

# Installation

```bash
sudo apt install python3-pip
pip3 install sphinx
```

# Usage

* Create new SPHINX project
  - Refer to [how to choose options](http://yf-tiger.com/IT/sphinx/html/rst/getting_started.html)

```bash
sphinx-quickstart
```

# Configuration

SPHINX configuration is under `conf.py`

* `html_theme`: The theme you want to use
  - pip3 install sphinx_rtd_theme
  - Modify html_theme to `html_theme = 'sphinx_rtd_theme'`

# Themes/Plugins

* sphinx_rtd_theme: The theme which is same as [navigation2 official website](https://navigation.ros.org/)
* sphinxcontrib-plantuml: Able to draw UML

# Reference
* [Official website](https://www.sphinx-doc.org)
