FROM ubuntu:22.04 As builder

WORKDIR /app

RUN apt-get update -yqq \
    && apt-get install -yqq --no-install-recommends software-properties-common cmake libsqlite3-dev pip g++ make &&\
    pip install conan
    

COPY conanfile.txt .

RUN  conan profile detect && conan install . --build=missing 

COPY . .

RUN cd build && cmake .. -DCMAKE_TOOLCHAIN_FILE=Release/generators/conan_toolchain.cmake\
                         -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH=build/Release/generators && cmake --build . 

