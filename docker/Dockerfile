FROM registry.fedoraproject.org/fedora-minimal:30

RUN microdnf -y --setopt=tsflags=nodocs install \
        arm-none-eabi-binutils-cs \
        arm-none-eabi-gcc-cs \
        arm-none-eabi-gcc-cs-c++ \
        arm-none-eabi-newlib \
        dfu-util \
        diffutils \
        git-core \
        make \
        patch \
    && microdnf -y clean all

#RUN microdnf -y --setopt=tsflags=nodocs install \
#        avr-binutils \
#        avr-gcc \
#        avr-gcc-c++ \
#        avr-libc \
#        avrdude \
#        dfu-programmer \
#        gcc \
#        gcc-c++ \
#        wget \
#        zip unzip \
#    && microdnf -y clean all

VOLUME  /build
WORKDIR /build
CMD make
