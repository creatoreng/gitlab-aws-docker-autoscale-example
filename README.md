# Gitlab autoscaling with docker + AWS code example
> Example source code that may be used with the gitlab runner
configured by [creatoreng/gitlab-aws-docker-autoscale](https://github.com/creatoreng/gitlab-aws-docker-autoscale).

This repository is an example of code that can be compiled,
tested and artifaced by the gitlab runner configured by
the Ansible scripts in [creatoreng/gitlab-aws-docker-autoscale](https://github.com/creatoreng/gitlab-aws-docker-autoscale).

### Features
* `.gitlab-ci.yml` that defines pipeline stages and jobs to compile
the example code in this repo.
* "Hello world" C++ source to be compiled, tested and artifacts uploaded to S3.
* Dummy example of an external library that will be cached in S3 as a build dependency.
* Build script that compiles all code. Assumes `g++`
is present in the command-line.

# How to use this code
- Provision your VPC and gitlab runner following [creatoreng/gitlab-aws-docker-autoscale](https://github.com/creatoreng/gitlab-aws-docker-autoscale).
- Clone this repo to a public repo in your source control service (Github, etc.).
- Modify `.gitlab-ci.yml` and replace 'gitlab-artifact-unique-identifier'
with the name of your S3 bucket.
  - Comment this job out if you have not configured an S3 bucket.
- Configure a Gitlab CI/CD project that builds code from your modified example repo.
- Run a pipeline by manually triggering or committing to the `main` branch.
