template            c++11
name                NetCleanFrameServer
sourcedir           src
cflags              std=c++0x Wall static
ldflags             static-libgcc static-libstdc++ Wl,--enable-auto-image-base Wl,--add-stdcall-alias Wl,--enable-auto-import Wl,-Bstatic
target_platform     mingw32
lib-static          libvx libshmipc
