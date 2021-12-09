FROM ubuntu

# Install tools
RUN apt-get update
RUN apt-get install -y --no-install-recommends \
    libfcgi-dev \
    spawn-fcgi \
    nginx \
    g++ \
    wget

# Install Go
RUN wget -c https://go.dev/dl/go1.17.4.linux-amd64.tar.gz --no-check-certificate -O - | tar -xz -C /usr/local

# Install Gx
RUN mkdir -p /usr/local/gx/bin
COPY bin/gx /usr/local/gx/bin

# Nginx config
COPY conf/nginx.conf /etc/nginx/nginx.conf
EXPOSE 80

# Run
ENV PATH="$PATH:/usr/local/go/bin:/usr/local/gx/bin"
WORKDIR /gx-web
CMD nginx && bash -C '/gx-web/run.sh';'bash'
