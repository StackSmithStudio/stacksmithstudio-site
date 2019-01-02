provider "digitalocean" {
  version = "0.1.3"
  token   = "${chomp(file("~/.config/digital-ocean/token"))}"
  alias   = "default"
}

provider "local" {
  version = "~> 1.0"
  alias   = "default"
}

provider "null" {
  version = "~> 1.0"
  alias   = "default"
}

provider "template" {
  version = "~> 1.0"
  alias   = "default"
}

provider "tls" {
  version = "~> 1.0"
  alias   = "default"
}

module "digital-ocean-stacksmithstudio" {
  source = "git::https://github.com/poseidon/typhoon//digital-ocean/container-linux/kubernetes?ref=v1.11.1"

  providers = {
    digitalocean = "digitalocean.default"
    local        = "local.default"
    null         = "null.default"
    template     = "template.default"
    tls          = "tls.default"
  }

  # Digital Ocean
  cluster_name = "stacksmithstudio-k8"
  region       = "nyc1"
  dns_zone     = "stacksmithstudio.com"

  # configuration
  ssh_fingerprints = ["06:69:bc:6d:f6:fc:df:30:d7:ec:8a:2d:01:c6:35:6e"]
  asset_dir        = "/Users/GT/.secrets/clusters/stacksmithstudio"

  # optional
  worker_count    = 1
  controller_type = "s-1vcpu-2gb"
  worker_type     = "s-1vcpu-2gb"
}
