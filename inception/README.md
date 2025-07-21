# Inception

A comprehensive Docker infrastructure project that demonstrates system administration concepts through containerization. This project creates a small-scale infrastructure using Docker Compose, featuring a WordPress website with database backend, along with several additional services for enhanced functionality and monitoring.

## Project Overview

Inception is a Docker-based project that builds a complete web infrastructure from scratch. The project emphasizes security, performance, and best practices in containerization, featuring custom-built Docker images rather than pre-made solutions from Docker Hub.

### Key Features

- **Custom Docker Images**: All services built from scratch using Debian Bullseye
- **SSL/TLS Security**: NGINX configured with TLSv1.2 and TLSv1.3 protocols
- **Persistent Storage**: Data volumes mounted to host filesystem
- **Service Isolation**: Each service runs in its dedicated container
- **Automatic Restart**: All containers configured for automatic restart on failure
- **Comprehensive Monitoring**: Full metrics collection and visualization stack

## Architecture

The infrastructure consists of multiple interconnected services running on a custom Docker network called `inception`. All services communicate internally while NGINX serves as the sole entry point accessible from the external network.

```
                    ┌─────────────┐
                    │    NGINX    │ ◄── Entry Point (443)
                    │   (443/81)  │
                    └─────────────┘
                           │
          ┌────────────────┼────────────────┐
          │                │                │
          ▼                ▼                ▼
┌─────────────┐    ┌─────────────┐    ┌─────────────┐
│  WordPress  │◄──►│   MariaDB   │    │ Static Site │
│   (9000)    │    │   (3306)    │    │    (80)     │
└─────────────┘    └─────────────┘    └─────────────┘
          │                │
          ▼                ▼
┌─────────────┐    ┌─────────────┐
│    Redis    │    │   Adminer   │
│   (6379)    │    │   (8080)    │
└─────────────┘    └─────────────┘

         Monitoring & File Transfer Layer
┌─────────────┐    ┌─────────────┐    ┌─────────────┐
│   Grafana   │◄──►│ Prometheus  │    │ FTP Server  │
│             │    │   (9090)    │    │    (21)     │
└─────────────┘    └─────────────┘    └─────────────┘
                           ▲
          ┌────────────────┼────────────────┐
          │                │                │
          ▼                ▼                ▼
┌─────────────┐    ┌──────────────┐   ┌─────────────┐
│NGINX Export │    │MariaDB Export│   │Redis Export │
│   (9113)    │    │   (9104)     │   │   (9121)    │
└─────────────┘    └──────────────┘   └─────────────┘

┌─────────────────────────────────────────────────────┐
│                Inception Network                    │
└─────────────────────────────────────────────────────┘
```

## Mandatory Services

### NGINX

- **Purpose**: Reverse proxy and SSL termination
- **Configuration**: TLS 1.2/1.3 only, custom SSL certificates
- **Ports**: 443 (HTTPS), 81 (metrics endpoint)
- **Features**:
  - HTTP to HTTPS redirection
  - SSL certificate auto-generation
  - WordPress PHP-FPM proxy
  - Nginx status endpoint for monitoring

### WordPress

- **Purpose**: Content Management System
- **Configuration**: PHP 7.4 with PHP-FPM
- **Dependencies**: MariaDB for database, Redis for caching
- **Features**:
  - WP-CLI for automated setup
  - Redis cache integration
  - Custom user creation (admin + standard user)
  - Persistent file storage

### MariaDB

- **Purpose**: Database backend
- **Configuration**: Custom configuration with optimizations
- **Features**:
  - Automated database initialization
  - Secure user management
  - Performance tuning
  - Data persistence

## Bonus Services

### Redis Cache

- **Purpose**: WordPress object caching
- **Features**:
  - Password authentication
  - Persistent data storage
  - Performance monitoring
  - Custom configuration

### FTP Server (vsftpd)

- **Purpose**: File transfer to WordPress directory
- **Configuration**: Passive mode with port range 30000-30009
- **Security**: User authentication with chroot jail
- **Access**: Direct connection to WordPress file volume

### Adminer

- **Purpose**: Database administration interface
- **Access**: Web-based interface on port 8080
- **Features**:
  - MariaDB database management
  - User-friendly SQL operations
  - Import/export capabilities

### Static Website

- **Purpose**: It is on the cadet's choice (in my case it provides basic overview of the project in italian)
- **Technology**: HTML, CSS, JavaScript
- **Content**: Project documentation and information
- **Features**: Responsive design, modern styling

### Monitoring Stack

#### Prometheus

- **Purpose**: Metrics collection and storage
- **Features**:
  - Multi-target scraping
  - Time-series database
  - Service discovery
  - Alert management capabilities

#### Grafana

- **Purpose**: Metrics visualization and dashboards
- **Features**:
  - Pre-configured dashboards for all services
  - Real-time monitoring
  - Custom alerting rules
  - Professional visualizations

#### Exporters

- **NGINX Exporter**: Collects NGINX performance metrics
- **MariaDB Exporter**: Database performance and health metrics
- **Redis Exporter**: Cache performance and memory usage

## Project Structure

```
inception/
├── Makefile                    # Build and management commands
├── srcs/
│   ├── docker-compose.yml      # Service orchestration
│   ├── .env                    # Environment variables
│   └── requirements/
│       ├── nginx/              # NGINX reverse proxy
│       ├── wordpress/          # WordPress CMS
│       ├── mariadb/            # Database service
│       └── bonus/
│           ├── redis/          # Cache service
│           ├── ftp/            # File transfer
│           ├── adminer/        # DB admin
│           ├── static_site/    # Portfolio site
│           ├── prometheus/     # Metrics collection
│           ├── grafana/        # Visualization
│           └── metrics/        # Metric exporters
│               ├── nginx/
│               ├── mariadb/
│               └── redis/
```

## Quick Start

### Prerequisites

- Docker and Docker Compose installed
- Domain name configured (your login.42.fr, where login is your 42 nickname)
- Sufficient disk space for volumes

### Installation

1. **Clone and navigate to the project**:

   ```bash
   git clone https://github.com/denuen/42_cursus.git
   cd inception
   ```

2. **Create environment file**:

   ```bash
   mv srcs/.env.template srcs/.env
   # Edit .env with your configuration
   ```

3. **Build and start all services**:

   ```bash
   make all
   ```

4. **Verify deployment**:
   ```bash
   make status
   ```

### Available Commands

```bash
make all          # Build and start all services
make build        # Build Docker images
make up           # Start services
make down         # Stop services
make clean        # Clean containers and images
make fclean       # Full cleanup including volumes
make re           # Rebuild everything
make logs         # View all service logs
make status       # Check service status
```

### Service-specific logs:

```bash
make nginx-logs       # NGINX logs
make wordpress-logs   # WordPress logs
make mariadb-logs     # Database logs
make redis-logs       # Redis logs
make grafana-logs     # Grafana logs
```

## Security Features

- **SSL/TLS Encryption**: All web traffic encrypted with modern protocols
- **Network Isolation**: Services communicate only through internal network
- **Credential Management**: Environment variables for sensitive data
- **User Permissions**: Proper file permissions and user isolation
- **Database Security**: Dedicated users with minimal privileges

## Monitoring & Observability

The project includes a comprehensive monitoring stack:

- **Prometheus**: Collects metrics from all services
- **Grafana**: Provides beautiful dashboards and alerting
- **Exporters**: Specialized metric collectors for each service

### Accessing Monitoring

- **Grafana Dashboard**: https://yourlogin.42.fr/grafana
- **Prometheus**: Internal service (accessible via Grafana)
- **Individual Metrics**: Each exporter provides detailed service metrics

## Data Persistence

All critical data is persisted using Docker volumes mapped to the host filesystem:

- **MariaDB Data**: `/Users/denuen/data/mariadb`
- **WordPress Files**: `/Users/denuen/data/wordpress`
- **Redis Data**: `/Users/denuen/data/redis`
- **Monitoring Data**: `/Users/denuen/data/prometheus` & `/Users/denuen/data/grafana`

To make them persistent on your system, the path must be changed with one of you choice or just replace "denuen" with your hostname in the Makefile and also in the docker-compose.yml

## Service Access

- **WordPress Site**: https://yourlogin.42.fr
- **Database Admin**: http://yourlogin.42.fr/adminer
  - **Username**: Set in `MYSQL_USER` environment variable
  - **Password**: Set int `MYSQL_PASSWORD`environment variable
  - **Server**: mariadb
- **FTP Server**: Connect using FTP client to `yourlogin.42.fr:21`
  - **Username**: Set in `FTP_USER` environment variable
  - **Password**: Set in `FTP_PASSWORD` environment variable
  - **Directory**: Points to WordPress files volume
  - **Ports**: 21 (control), 30000-30009 (passive data)
- **Static Site**: https://yourlogin.42.fr/docs
- **Grafana**: https://yourlogin.42.fr/grafana

## Technical Specifications

- **Base Image**: Debian Bullseye (stable)
- **Network**: Custom bridge network `inception`
- **SSL**: Self-signed certificates with automatic generation
- **PHP**: Version 7.4 with FPM configuration
- **Database**: MariaDB latest stable
- **Web Server**: NGINX with reverse proxy configuration

## Learning Outcomes

This project demonstrates mastery of:

- **Docker & Containerization**: Building custom images, multi-service orchestration
- **System Administration**: Service configuration, networking, security
- **Web Technologies**: NGINX configuration, PHP-FPM, SSL/TLS
- **Database Management**: MariaDB setup, user management, optimization
- **Monitoring**: Prometheus metrics, Grafana visualization
- **DevOps Practices**: Infrastructure as code, automation, best practices

## Credits

Developed by [denuen](https://github.com/denuen) as part of the 42 School curriculum. Special thanks to the 42 community for guidance and support in mastering low-level file reading techniques.
