import argparse

parser = argparse.ArgumentParser(description="puertos para scanear")

parser.add_argument(
    "-t",
    dest="target",
    help="target",
    required=True
)

parser.add_argument(
    "-p",
    "--port",
    dest="port",
    type=int,
    default=80,
    help="puerto para escanear = 80"
)

parser.add_argument(
    "-v",
    dest="verbosity",
    help="nivel de verbosidad",
    type=int,
    default=0
)

parser.add_argument(
    "--open",
    dest="only_open",
    action="store_true",
    help="solo mostrar puertos abiertos"
)

params = parser.parse_args()

print("target:", params.target)
print("port:", params.port)
print("verbosity:", params.verbosity)
print("only_open:", params.only_open)