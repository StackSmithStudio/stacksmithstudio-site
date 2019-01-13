FROM node:10.11.0

# Install yarn
RUN apt-get update && apt-get install -y apt-transport-https
RUN apt-get install -y build-essential libpng-dev zlib1g-dev
RUN curl -sS https://dl.yarnpkg.com/debian/pubkey.gpg | apt-key add -
RUN echo "deb https://dl.yarnpkg.com/debian/ stable main" | tee /etc/apt/sources.list.d/yarn.list
RUN apt-get update && apt-get install yarn

# update with the dockerfile
RUN yarn global add bs-platform@4.0.5

RUN yarn global add reason-cli@3.2.0-darwin

RUN yarn global add gatsby --no-optional gatsby@2.0.8



# RUN apt-get update \
#     && apt-get install -y build-essential libpng-dev zlib1g-dev \
#     && yarn \
#     && yarn run build \
#     && yarn cache clean \
#     && find public -regextype posix-basic -regex '.*\.\(js\|css\)\(.map\)\?$' | xargs -I@ sh -c "gzip -c @ > @.gz" \
#     && rm -Rf node_modules \
#     && apt-get remove -y build-essential libpng-dev zlib1g-dev \
#     && apt-get clean




# Copy just the package.json first to install deps
ADD /src /src
ADD /static /static

ADD .babelrc .
ADD package.json .
ADD bsconfig.json .
ADD tailwind.js .
ADD yarn.lock .
ADD postcss.config.js .
ADD gatsby-config.js .
ADD gatsby-node.js .

WORKDIR .

ENV GATSBY_DIR "/site"
ENV PATH "${PATH}:/usr/local/bin/gatsby"

# install dependencies via npm
RUN yarn --pure-lockfile

# src folders
COPY ./src "${GATSBY_DIR}/src"
COPY ./static "${GATSBY_DIR}/static"

# platform files
COPY ./.babelrc "${GATSBY_DIR}/"
COPY ./package.json "${GATSBY_DIR}/"
COPY ./bsconfig.json "${GATSBY_DIR}/"
COPY ./tailwind.js "${GATSBY_DIR}/"
COPY ./yarn.lock "${GATSBY_DIR}/"
COPY ./postcss.config.js "${GATSBY_DIR}/"
COPY ./gatsby-config.js "${GATSBY_DIR}/"
COPY ./gatsby-node.js "${GATSBY_DIR}/"

RUN rm -rf "${GATSBY_DIR}/public"
WORKDIR $GATSBY_DIR

# Now add source code & build
RUN yarn build

RUN rm -rf /webapp/*
RUN rm -rf /node_modules
RUN mkdir -p /webapp
RUN mv ${GATSBY_DIR}/public/* /webapp/

EXPOSE 8000

# convert to multi part dockerfile

# FROM node:10.11.0 as builder

# RUN apt-get update && apt-get install -y apt-transport-https
# RUN curl -sS https://dl.yarnpkg.com/debian/pubkey.gpg | apt-key add -
# RUN echo "deb https://dl.yarnpkg.com/debian/ stable main" | tee /etc/apt/sources.list.d/yarn.list
# RUN apt-get update && apt-get install yarn
# RUN apt-get install -y python

# RUN apt-get install -y build-essential libpng-dev zlib1g-dev
# # RUN yarn

# RUN yarn global add gatsby --no-optional gatsby@2.0.8

# # add bucklescript
# RUN yarn global add bs-platform
# RUN yarn global add reason-cli@3.2.0-darwin

# # RUN yarn run build
# # RUN yarn cache clean
# # RUN find public -regextype posix-basic -regex '.*\.\(js\|css\)\(.map\)\?$' | xargs -I@ sh -c "gzip -c @ > @.gz"
# # RUN rm -Rf node_modules
# # RUN apt-get remove -y build-essential libpng-dev zlib1g-dev
# # RUN apt-get clean






# # hmmmm?



# RUN npm install -g bs-platform --unsafe-perm

# RUN yarn install

# RUN mkdir -p /site


# WORKDIR /site
# VOLUME /site

# # build script
# COPY ./entry.sh /

# # src folders
# COPY ./src /site/src
# COPY ./static /site/static

# # platform files
# COPY ./.babelrc /site/
# COPY ./gatsby-config.js /site/
# COPY ./gatsby-node.js /site/
# COPY ./package.json /site/
# COPY ./bsconfig.json /site/
# COPY ./tailwind.js /site/
# COPY ./postcss.config.js /site/
# ENV GATSBY_DIR "/site"
# ENV PATH "${PATH}:/usr/local/bin/gatsby"

# RUN echo "gatsby build"
# RUN rm -rf public

# RUN yarn build

# RUN rm -rf /webapp/*
# RUN mv /site/public/* /webapp/

# #####################################################################
# # RUN apk update && \
# #     apk add --update --repository http://dl-3.alpinelinux.org/alpine/edge/testing --repository http://dl-3.alpinelinux.org/alpine/edge/main vips-tools vips-dev fftw-dev gcc g++ make libc6-compat && \
# #     apk add git && \
# #     apk add python && \
# #     apk add yarn && \
# #     rm -rf /var/cache/apk/*

# # add gatsby
# # RUN yarn global add gatsby --no-optional gatsby@2.0.8

# # add bucklescript
# # RUN yarn global add bs-platform
# # RUN yarn global add reason-cli@3.2.0-darwin




# FROM alpine:3.8

# RUN mkdir -p /site

# WORKDIR /site
# VOLUME /site

# COPY --from=builder /site /site

# EXPOSE 8000


# # RUN chmod +x /entry.sh
# # ENTRYPOINT ["/entry.sh", "build"]
