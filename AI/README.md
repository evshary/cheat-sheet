# AI

## Common concepts

* Terminology:
  * Expert Systems (Database)
  * Logic Programming (Based on logic)
  * Machine Learning
    * Regression/Classification: SVM, Naive Bayes
    * Tree-Based Models: Decision Trees, Random Forests
    * Clustering: K-Means
    * Reinforcement Learning
    * Deep Learning:
   	  * Sequential/Language/Action
   	    * RNN
   	    * Transformer (GPT)
 	  * Image/Spatial
 	    * CNN
 	    * Vision Transformer (ViT)
 	  * Generative/Unsupervised
 	    * GANs
 	    * Diffusion Models (Midjourney)
* Robots:
  * Imitation Learning: Learn basic skills
  * Reinforcement Learning: Learn in complicated scenarios
  * VLA (Vision-Language-Action Models): Receive humans' commands and react to the environment
* Application:
  * OpenCV: Computer vision library
  * GStreamer: Multi-media pipeline
  * Training:
    * PyTorch: Proposed by META, used in research (format: `.pt`, `.pth`)
      * HuggingFace:
        * Blueprint: config.json
        * Weights: pytorch_model.bin
    * TensorFlow: Proposed by Google, used in enterprises (format: SavedModel folder)
      * HuggingFace:
        * Blueprint: config.json
        * Weights: tf_model.h5
  * Inference:
    * TensorRT: Proposed by NVIDIA (format: `.engine`, `.plan`)
    * TFLite: Proposed by Google (format: `.tflite`)
    * Core ML: Proposed by Apple (format: `.mlmodel`, `.mlpackage`)
    * OpenVINO: Proposed by Intel (format: `.xml`, `.bin`)
    * ONNX: General framework for CPU, CUDA, TensorRT, OpenVINO... (format: .onnx)
    * ARM's NPU (Ethos) supports TFLite and ONNX

* NVIDIA Stack

```raw
+-----------------------------------------------------------------------+
|         Training                 |            Inference               |
|        PyTorch (META)            |        TensorRT (NVIDIA)           |
|     TensorFlow (Google)          |                                    |
+-----------------------------------------------------------------------+
|                   cuDNN (Optimized Primitives)                        |
|                CUDA Deep Neural Network Library.                      |
|           Provide deep learning functions based on CUDA.              |
+-----------------------------------------------------------------------+
|                 CUDA (development environment)                        |
|          Provide tool and library, like nvcc and runtime.             |
+-----------------------------------------------------------------------+
|              NVIDIA GPU driver (including CUDA driver)                |
|         CUDA driver: provide API for tools like nvidia-smi            |
+-----------------------------------------------------------------------+
|                      NVIDIA GPU (Hardware)                            |
+-----------------------------------------------------------------------+
```

## CUDA

Follow the instructions in [GPU.md](GPU.md) to install GPU driver (including CUDA driver) and CUDA toolkit.

## OpenCV

* Installation: If you want the latest version, you need to build from source

```shell
sudo apt install libopencv-dev -y
```

* The cmake location is under `/usr/lib/x86_64-linux-gnu/cmake/opencv4`

## PyTorch

* Download the library from [the official website](https://pytorch.org/get-started/locally/)

## ONNX

* Download the library from [GitHub](https://github.com/microsoft/onnxruntime/releases)

## TensorRT

* Download the library from [the official website](https://developer.nvidia.com/tensorrt)
* Install the library based on [the tutorial](https://docs.nvidia.com/deeplearning/tensorrt/latest/installing-tensorrt/installing.html)

```shell
sudo apt install ./<tensorrt.deb>
sudo cp /var/nv-tensorrt-local-repo-xxxx-yyyy/*-keyring.gpg /usr/share/keyrings/
sudo apt-get update
sudo apt install tensorrt-dev
```

## [TensorBoard](https://www.tensorflow.org/tensorboard?hl=zh-tw)

A visualization tool for TensorFlow.
