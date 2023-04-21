♟Chess
=============================
- [Environment Setup](#environment-setup)
	- [Operating System](#operating-system)
	- [Build essential tools](#build-essential-tools)
	- [Dependencies](#dependencies)
		-[Conan](#Conan)
		-[Vcpkg](#Vcpkg)
----------------------------------


# Environment Setup

### Operating System

This project has been depeloped and tested under the followings SO:

* `WSL` with `Ubuntu-22.04` `version 2`

To install, on `Powershell`:

1. Install `WSL`

2. Then, install `Ubuntu-22.04`. For that. list available distros: 
```bash
wsl --list --online
```
3. And then, install the desired distro. On our case, `Ubuntu-22.04`:
```bash
wsl --install Ubuntu-22.04
```

### Build essential tools

Compiler version checked:

* `gcc 11.3.0`

**NOTE:** This gcc version (GCC compiler>5.1) requires some configuration if recomended `Conan` is used. These configurations are explained on [Dependencies](#dependencies).

To install basic build essentials, like `gcc`, `g++` and `make`, on wsl with `Ubuntu-22.04`, follow those steps:

1. Update the avalaible packages:
```bash
sudo apt update
```
2. Install `build-essential`:
```bash
sudo apt install build-essential
```
3. Optionally, manual pages also can be installed:
```bash
sudo apt-get install manpages-dev
```
For compile using `CMake`, is needed to install as well:

```bash
sudo apt install cmake
```

### 📦Dependencies

This project has external dependencies with the following libraries:

* `sfml`, version used is `2.5.1`.

* `gtest`, version used is `cci.20210126`.

However, we have multiple package managers that make our work easier. In this section, we propose two of them, of which a simple explanation is provided to use them to deploy the project `In this section, we propose two of them, of which a simple explanation is provided to use them to deploy the project. You can use either one.


#### [Conan](https://conan.io/)
First package manager that we propose, is `Conan`, For that, is nessecary to have `Conan` installed. For this proyect, we propose `Conan 1`, specifically the version `Conan 1.59`.

For install it, follow the next steps:

1. Install `pip`:

```bash
sudo apt install pip
```

2. Install `Conan` specifying the version:

```bash
pip install conan==1.59
```

**IMPORTANT**: Is necessary to restart WSL to start using Conan. For that, in `Powershell`: 
1. Shutdown `WSL`:
```bash
wsl --shutdown
```
2. Start `WSL`:
```bash
wsl
```

Optionally, to not have to install necessary packages by hand, is possible to configure `Conan` for do it automatically. For that, follow the next steps.

1. If not exist, create `Conan` configuration file on `~/.conan/global.conf`.

2. Add the following configuration lines:

```bash
tools.system.package_manager:mode = install
tools.system.package_manager:sudo = True
```

Even so, could be necessary to install pkg-config:
 ```bash
sudo apt install pkg-config
```

As is mentioned on section [Build essential tools](#build-essential-tools), is necessary to specify that we want to use `libstdc++11` to link, that is used by `CMake`. By default, `Conan` is configured to use `libstdc++`, so is necessary to specify this on our `Conan profile configuration`:

 ```bash
conan profile update settings.compiler.libcxx=libstdc++11 default
```

If the default profile is not created, could be created with the following comand:
```bash
conan profile new default --detect
```

For more details, also can visit [Conan documentation, Getting Started section.](https://docs.conan.io/1/getting_started.html#an-md5-hash-calculator-using-the-poco-libraries)
