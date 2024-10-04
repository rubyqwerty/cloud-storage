FROM drogonframework/drogon

WORKDIR /app

COPY . .

RUN mkdir build && cd build && cmake .. && cmake --build . 