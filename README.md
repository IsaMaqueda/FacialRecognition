# Final Project: Automatic Face Recognition System
## TC2004 Analysis and modeling of software systems

Tecnológico de Monterrey, CSF

Professor: Dr. Leonardo Chang Fernández (lchang@tec.mx)

Semester: Jan-May 2019. 

## Introduction

The best way to learn Software Engineering is writing and designing a lot of code in teams. The goal of the final project is to develop a large computer system that solves a real-world problem, following the life cycle of software development. In particular we will create an __automatic face recognition system__.

The project will be conducted in teams, where each team will do everything: capture requirements, design, implement and test the system.

This project will be very similar to the experience of a _startup_ 😃

__Team 1: Image capture and face detection.__ This module is responsible for obtaining images from different sources, for example, .jpg files, .mp4 videos and webcams. Also, given an image, this module must be able to detect the existing faces in it.

__Team 2: Detection of landmarks and face alignment.__ This module receives as input an image and the region of the face in it. The module must be able to detect on the face region several landmark points that will serve as reference for the transformations needed to obtain an  aligned face, which is also the objective of this module.

__Team 3: Face features extraction and comparison.__ This module, from an aligned face, extracts the biometric features, obtaining a descriptor. Then, this descriptor must be compared with others in tasks of verification and / or identification of subjects.

__Team 4: Biometric database.__ This module is responsible for the persistence and indexing of system data. For example, store and retrieve face images, face features, biographical data, identity, etc.
