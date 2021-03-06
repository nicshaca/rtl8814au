<!DOCTYPE HTML>
<html>
<head>
<style>
.swipeable {
  overflow: scroll;
  height: 200px;
  width: 200px;
}
.left-right-item,
.top-bottom-item {
  height: 100px;
  width: 100px;
}
.left-right-item {
  display: inline-block;
}
.red-bg {
  background-color: red;
}
.blue-bg {
  background-color: blue;
}
.tall-and-wide {
  background-color: grey;
  height: 5000px;
  width: 5000px;
}
</style>
</head>
<body>

<div id="left-right" class="swipeable">
  <div style="width: 1000px;">
    <div class="left-right-item red-bg">Test</div>
    <div class="left-right-item blue-bg">Test</div>
    <div class="left-right-item red-bg">Test</div>
    <div class="left-right-item blue-bg">Test</div>
  </div>
</div>

<div id="top-bottom" class="swipeable">
  <div class="top-bottom-item red-bg">Test</div>
  <div class="top-bottom-item blue-bg">Test</div>
  <div class="top-bottom-item red-bg">Test</div>
  <div class="top-bottom-item blue-bg">Test</div>
</div>

<div class="tall-and-wide"></div>

<div id="off-screen"></div>
</body>
</html>
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                {
  "config_type": "BaseConfig",
  "dependencies": {
    "aapt": {
      "cloud_storage_base_folder": "binary_dependencies",
      "cloud_storage_bucket": "chromium-telemetry",
      "file_info": {
        "linux2_x86_64": {
          "cloud_storage_hash": "16ba3180141a2489d7ec99b39fd6e3434a9a373f",
          "download_path": "../bin/deps/linux2/x86_64/bin/aapt"
        }
      }
    },
    "adb": {
      "cloud_storage_base_folder": "binary_dependencies",
      "cloud_storage_bucket": "chromium-telemetry",
      "file_info": {
        "linux2_x86_64": {
          "cloud_storage_hash": "8bd43e3930f6eec643d5dc64cab9e5bb4ddf4909",
          "download_path": "../bin/deps/linux2/x86_64/bin/adb"
        }
      }
    },
    "android_build_tools_libc++": {
      "cloud_storage_base_folder": "binary_dependencies",
      "cloud_storage_bucket": "chromium-telemetry",
      "file_info": {
        "linux2_x86_64": {
          "cloud_storage_hash": "91cdce1e3bd81b2ac1fd380013896d0e2cdb40a0",
          "download_path": "../bin/deps/linux2/x86_64/lib/libc++.so"
        }
      }
    },
    "chromium_commands": {
      "cloud_storage_base_folder": "binary_dependencies",
      "cloud_storage_bucket": "chromium-telemetry",
      "file_info": {
        "linux2_x86_64": {
          "cloud_storage_hash": "4e22f641e4757309510e8d9f933f5aa504574ab6",
          "download_path": "../bin/deps/linux2/x86_64/lib.java/chromium_commands.dex.jar"
        }
      }
    },
    "dexdump": {
      "cloud_storage_base_folder": "binary_dependencies",
      "cloud_storage_bucket": "chromium-telemetry",
      "file_info": {
        "linux2_x86_64": {
          "cloud_storage_hash": "acfb10f7a868baf9bcf446a2d9f8ed6b5d52c3c6",
          "download_path": "../bin/deps/linux2/x86_64/bin/dexdump"
        }
      }
    },
    "fastboot": {
      "cloud_storage_base_folder": "binary_dependencies",
      "cloud_storage_bucket": "chromium-telemetry",
      "file_info": {
        "linux2_x86_64": {
          "cloud_storage_hash": "db9728166f182800eb9d09e9f036d56e105e8235",
          "download_path": "../bin/deps/linux2/x86_64/bin/fastboot"
        }
      }
    },
    "forwarder_device": {
      "cloud_storage_base_folder": "binary_dependencies",
      "cloud_storage_bucket": "chromium-telemetry",
      "file_info": {
        "android_arm64-v8a": {
          "cloud_storage_hash": "90cc60cefb497512d95d774045146754c477b433",
          "download_path": "../bin/deps/android/arm64-v8a/bin/forwarder_device"
        },
        "android_armeabi-v7a": {
          "cloud_storage_hash": "3a5ade8fbaffea3b0670bffaa845288db5e4d567",
          "download_path": "../bin/deps/android/armeabi-v7a/bin/forwarder_device"
        }
      }
    },
    "forwarder_host": {
      "cloud_storage_base_folder": "binary_dependencies",
      "cloud_storage_bucket": "chromium-telemetry",
      "file_info": {
        "linux2_x86_64": {
          "cloud_storage_hash": "63653293098d7fe17aa115b147c8d9aa253b0912",
          "download_path": "../bin/deps/linux2/x86_64/forwarder_host"
        }
      }
    },
    "md5sum_device": {
      "cloud_storage_base_folder": "binary_dependencies",
      "cloud_storage_bucket": "chromium-telemetry",
      "file_info": {
        "android_arm64-v8a": {
          "cloud_storage_hash": "4e7d2dedd9c6321fdc152b06869e09a3c5817904",
          "download_path": "../bin/deps/android/arm64-v8a/bin/md5sum_device"
        },
        "android_armeabi-v7a": {
          "cloud_storage_hash": "39fd90af0f8828202b687f7128