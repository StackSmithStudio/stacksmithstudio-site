FROM node:10.11-alpine

EXPOSE 8000

RUN apk update && \
    apk add --update --repository http://dl-3.alpinelinux.org/alpine/edge/testing vips-tools vips-dev fftw-dev gcc g++ make libc6-compat && \
    apk add git && \
    apk add python && \
    apk add yarn && \
    rm -rf /var/cache/apk/*

# add gatsby
RUN yarn global add gatsby --no-optional gatsby@2.0.8

# add bucklescript
RUN yarn global add bs-platform
RUN yarn global add reason-cli@3.2.0-darwin

RUN mkdir -p /site
WORKDIR /site
VOLUME /site

# build script
COPY ./entry.sh /

# src folders
COPY ./src /site/src
COPY ./static /site/static

# platform files
COPY ./.babelrc /site/
COPY ./gatsby-config.js /site/
COPY ./gatsby-node.js /site/
COPY ./package.json /site/
COPY ./bsconfig.json /site/
COPY ./tailwind.js /site/
COPY ./postcss.config.js /site/


RUN chmod +x /entry.sh
ENTRYPOINT ["/entry.sh", "build"]
