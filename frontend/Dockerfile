FROM node:10.11.0 as builder

ARG PROJ_DIR=/site
ENV GATSBY_DIR=${PROJ_DIR} PATH="${PATH}:/usr/local/bin/gatsby"

WORKDIR ${PROJ_DIR}
ADD . ${GATSBY_DIR}

# Install yarn
RUN apt-get update && apt-get install -y apt-transport-https \
  && apt-get install -y build-essential libpng-dev zlib1g-dev \
  && curl -sS https://dl.yarnpkg.com/debian/pubkey.gpg | apt-key add - \
  && echo "deb https://dl.yarnpkg.com/debian/ stable main" | tee /etc/apt/sources.list.d/yarn.list \
  && apt-get update && apt-get install yarn \
  && yarn global add bs-platform@4.0.5 \
  && yarn global add reason-cli@3.2.0-darwin \
  && yarn global add gatsby --no-optional gatsby@2.0.91
  # && cd /site \
  # && pwd \
  # && yarn --pure-lockfile \
  # && rm -rf /site/public \
  # && yarn build \
  # && rm -rf node_modules \
  # && apt-get remove -y build-essential libpng-dev zlib1g-dev \
  # && apt-get clean

# FROM alpine:3.8
# https://stackoverflow.com/a/52181893/923636

# COPY --from=builder /site/public/* /webapp/
# RUN ls -l /webapp

# ENTRYPOINT ["mv", "/site/public/*", "/webapp/"]
RUN chmod +x /site/other_entry.sh
ENTRYPOINT ["/site/other_entry.sh"]
