# TorConnect

**TorConnect** is a lightweight C program that routes HTTP requests securely through the Tor network using a SOCKS5 proxy. It ensures anonymity by preventing DNS leaks and hides your real IP address behind the Tor exit nodes.

---

## Overview

TorConnect is built using **libcurl**, allowing developers and security enthusiasts to perform HTTP requests through Tor seamlessly.
It is designed to be minimal, portable, and efficient — perfect for testing, research, or integrating Tor connectivity into other C-based applications.

---

## Features

* **SOCKS5 Proxy Support**: Routes all traffic through the Tor SOCKS5 proxy (`127.0.0.1:9050`).
* **DNS Leak Protection**: Uses `CURLPROXY_SOCKS5_HOSTNAME` to ensure hostname resolution is done over Tor, not locally.
* **Simple CLI Interface**: Easy to use with basic command-line input.
* **Secure Communication**: All traffic goes through the Tor network, providing anonymity.
* **Lightweight Implementation**: Minimal dependencies and code footprint.

---

## Requirements

Before building or running TorConnect, ensure the following are installed:

* **Tor** (running locally on port `9050`)
* **libcurl** (development package, e.g., `libcurl4-openssl-dev`)
* **gcc** or any C compiler

You can install the required packages on Debian/Kali-based systems using:

```bash
sudo apt install tor libcurl4-openssl-dev
```

---

## Build Instructions

Clone the repository and compile the project:

```bash
git clone git@github.com:EpicNerdGuy/TorConnect.git
cd TorConnect
gcc main.c -o torconnect -lcurl
```

---

## Usage

Start the Tor service first:

```bash
sudo service tor start
```

Then run TorConnect:

```bash
./torconnect curl <URL>
```

### Example

```bash
./torconnect curl https://check.torproject.org/
```

If the setup is successful, the output should confirm that your request came from the Tor network.

---

## Project Structure

```
TorConnect/
├── main.c              # Main program file
├── util.h              # Header for utility functions and memory handling
├── README.md           # Documentation
```

---

## How It Works

1. Initializes the `libcurl` environment.
2. Connects to the Tor SOCKS5 proxy (`127.0.0.1:9050`).
3. Sets `CURLPROXY_SOCKS5_HOSTNAME` to route DNS lookups through Tor.
4. Performs an HTTP GET request to the provided URL.
5. Cleans up resources and exits.

---

## Notes

* The Tor service **must be running** before using TorConnect.
* Ensure that you use `CURLPROXY_SOCKS5_HOSTNAME` instead of `CURLPROXY_SOCKS5` to avoid DNS leaks.
* This project is for **educational and research purposes only**. Do not use it for malicious activities.

---
