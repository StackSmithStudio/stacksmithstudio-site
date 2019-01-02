# deploy project
## Create cluster

```
# create kubernetes cluster
cd infra/terraform/
ssh-add ~/.ssh/id_rsa
terraform init
terraform plan
terraform apply
```

## set up docker local images
```
docker-machine upgrade default
docker-machine env default
eval "$(docker-machine env default)"


# build site as docker
cd frontend
rm -rf node_modules # make script to clean
docker build -t stacksmithstudio-site .
docker tag stacksmithstudio-site gtdev87/stacksmithstudio-site
docker push gtdev87/stacksmithstudio-site

```

## build nginx as docker
cd nginx
docker build -t stacksmithstudio-nginx .
docker tag stacksmithstudio-nginx gtdev87/stacksmithstudio-nginx
docker push gtdev87/stacksmithstudio-nginx

## set up cluster
```
cd infra/kubernetes
export KUBECONFIG=/Users/GT/.secrets/clusters/stacksmithstudio/auth/kubeconfig

# setup volume creation in digital ocean
# ask for digital ocean seacret
kubectl create -f ~/digitalocean-secret.yml

# this is for volume creation for pvs
kubectl apply -f https://raw.githubusercontent.com/digitalocean/csi-digitalocean/master/deploy/kubernetes/releases/csi-digitalocean-v0.2.0.yaml

# setup ingress in digital ocean environment
kubectl create -R -f typhoon/addons/nginx-ingress/digital-ocean/

# setup ingress for site
kubectl create -f ingress-setup.yaml

# install helm before this
helm init

# this is a TEMOPORARY FIX because of https://github.com/jetstack/cert-manager/issues/606#issuecomment-396909954

openssl req -x509 -nodes -days 1 -newkey rsa:2048 -keyout /tmp/tls.key -out /tmp/tls.crt -subj "/CN=stacksmithstudio.com"
kubectl create secret tls stacksmithstudio-secret --key /tmp/tls.key --cert /tmp/tls.crt

# setup https cert-manager
helm install --name cert-manager --namespace ingress --set ingressShim.defaultIssuerName=letsencrypt-prod --set ingressShim.defaultIssuerKind=ClusterIssuer stable/cert-manager

# create cluster issuer
kubectl create -n ingress -f clusterissuers.yaml

make clean
kompose up

```

# Point Digital ocean server to worker

point Type A www.stacksmithstudio.com to worker ip address


# To See absolutely everything
```
kubectl get all,ingress,pvc,pv,issuer,clusterissuer,certificate --all-namespaces
```


```
# to delete helm
kubectl get crd
helm del --purge cert-manager;
helm delete cert-manager
# remove all results in kubectl
```

## configure digital ocean @

A name
stacksmithstudio
www.stacksmithstudio
github.stacksmithstudio

# run dev locally
```
cd frontend
yarn install
gatsby develop
```
