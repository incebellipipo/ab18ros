#!/bin/sh

sudo apt-get update

sudo apt-get install -y \
  ros-kinetic-gazebo* \
  ros-kinetic-serial \
  ros-kinetic-move-base \
  ros-kinetic-global-planner \
  ros-kinetic-dwa-local-planner \
  ros-kinetic-joint-state-controller \
  ros-kinetic-joint-state-publisher \
  ros-kinetic-diff-drive-controller \
  ros-kinetic-controller* \
  ros-kinetic-robot-controllers \
  ros-kinetic-robot-pose-publisher \
  ros-kinetic-robot-state-publisher \
  ros-kinetic-urdf \
  ros-kinetic-tf-conversions \
  ros-kinetic-tf \
  ros-kinetic-tf2 \
  ros-kinetic-amcl \
  ros-kinetic-rosserial-python \
  ros-kinetic-joy-teleop \
  ros-kinetic-rospy \
  ros-kinetic-roscpp \
  ros-kinetic-tf2*
