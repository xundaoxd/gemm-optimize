#!/usr/bin/env python
import sys

import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

sns.set_theme()

import argparse


def parse_args(args = sys.argv[1:]):
    parser = argparse.ArgumentParser()
    parser.add_argument('--input', '-i', type=str, default='-')
    parser.add_argument('--output', '-o', type=str, default='-')
    return parser.parse_args(args)


def main(args):
    input = args.input
    output = args.output
    df = pd.read_csv(sys.stdin if input == '-' else input)
    df['algo'] = pd.Series(map(lambda x: x.split('/')[0], df['name']))
    df['index'] = pd.Series(map(lambda x: int(x.split('/')[-1]), df['name']))
    sns.relplot(
        x="index", y="cpu_time", kind="line",
        hue="algo",data=df,
    )
    if output == '-':
        plt.show()
    else:
        plt.savefig(output)


if __name__ == '__main__':
    main(parse_args())