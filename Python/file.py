import tensorflow as tf
print("TensorFlow version:", tf.__version__)
print("Available devices:", tf.config.list_physical_devices())

import jax
print("JAX version:", jax.__version__)
print("JAX devices:", jax.devices())