{
  "targets": [
    {
      "target_name": "native-utils",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [ "src/utils.cc", "src/clip.cpp", "src/image.cpp"],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      "conditions": [
        ["OS=='linux'", {
            "sources": [ "src/clip_x11.cpp"]
        }],

        ["OS=='mac'", {
            "sources": [ "src/clip_osx.mm"]
        }],

        ["OS=='win'", {
            "sources": [ "src/clip_win.cpp"]
        }]
    ],
    }
  ]
}
