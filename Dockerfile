FROM drogonframework/drogon As builder

WORKDIR /app

COPY . ./

RUN apt-get update  && \
    apt-get install -y \
    build-essential \
    libssl-dev \
    libsasl2-dev \
    pkg-config \
    wget \
    ca-certificates && \
    wget -c http://archive.ubuntu.com/ubuntu/pool/universe/f/fmtlib/libfmt-dev_4.0.0+ds-2_amd64.deb  &&\
    sudo apt install ./libfmt-dev_4.0.0+ds-2_amd64.deb && \ 
    wget -qO - https://packages.confluent.io/deb/7.0/archive.key | apt-key add - && \
    add-apt-repository "deb [arch=amd64] https://packages.confluent.io/deb/7.0 stable main" && \
    apt-get update && \
    apt-get install -y librdkafka-dev &&\
    mkdir build && cd build && \
    cmake .. && cmake --build . 

# Этап исполнения
FROM ubuntu:22.04
COPY --from=builder /app/build /app/build
COPY --from=builder /usr/lib /usr/lib
COPY --from=builder /lib /lib