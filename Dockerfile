FROM debian:bookworm-slim AS build

WORKDIR /app

RUN [ "apt-get", "update" ]

RUN [ "apt-get", "install", "-y", "--no-install-recommends", "git" ]
RUN [ "apt-get", "install", "-y", "--no-install-recommends", "make" ]
RUN [ "apt-get", "install", "-y", "--no-install-recommends", "gcc" ]
RUN [ "apt-get", "install", "-y", "--no-install-recommends", "libreadline-dev" ]
RUN [ "apt-get", "install", "-y", "--no-install-recommends", "ca-certificates" ]
RUN [ "git", "clone", "https://github.com/BenjaminRap/MINISHELL.git", "minishell" ]

WORKDIR /app/minishell

RUN [ "make", "all" ]

FROM debian:bookworm-slim

RUN [ "apt-get", "update" ]
RUN [ "apt-get", "install", "-y", "--no-install-recommends", "libreadline-dev" ]

COPY --from=build /app/minishell/minishell /bin/minishell

ENTRYPOINT [ "/bin/minishell" ]
