# AI

## Common concepts

* GPU: hardware
* CUDA driver: Part of the GPU driver. Take care of CUDA function and provide API for tools like nvidia-smi
* CUDA toolkit: Provide tool and library, like nvcc and runtime.
* cuDNN: Provide deep learning functions based on CUDA.
* Application:
  * OpenCV: Computer vision library
  * GStreamer: Multi-media pipeline
  * Training:
    * PyTorch: Proposed by META
    * TensorFlow: Proposed by Google
  * Inference:
    * TensorRT: Proposed by NVIDIA
    * OpenVINO: Proposed by Intel
    * ONNX: General framework for CPU, CUDA, TensorRT, OpenVINO...

## CUDA

* Follow the instructions in [GPU.md](GPU.md)
* The binaries should be under `/usr/local/cuda-12.x/`

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
