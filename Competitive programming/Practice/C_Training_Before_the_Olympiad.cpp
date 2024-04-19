# Install PySpark and Spark NLP
! pip install -q pyspark==3.3.0 spark-nlp==4.2.8

# Install Spark NLP Display lib
! pip install --upgrade -q spark-nlp-displ


import json
import pandas as pd
import numpy as np

import sparknlp
import pyspark.sql.functions as F

from pyspark.ml import Pipeline
from pyspark.sql import SparkSession
from sparknlp.annotator import *
from sparknlp.base import *
from sparknlp.pretrained import PretrainedPipeline
from pyspark.sql.types import StringType, IntegerType

spark = sparknlp.start()

print("Spark NLP version", sparknlp.version())
print("Apache Spark version:", spark.version)

spark

spark = SparkSession.builder \
    .appName("ner_task2") \
    .getOrCreate()

# Create the DocumentAssembler
document_assembler = DocumentAssembler() \
    .setInputCol("text") \
    .setOutputCol("document")

# Create the Tokenizer
tokenizer = Tokenizer() \
    .setInputCols(["document"]) \
    .setOutputCol("token")

# Download and configure the WordEmbeddingsModel
embeddings = WordEmbeddingsModel.pretrained("bengali_cc_300d", "bn") \
    .setInputCols(["document", "token"]) \
    .setOutputCol("embeddings")

# Download and configure the NerDLModel for named entity recognition
ner = NerDLModel.pretrained("bengaliner_cc_300d", "bn") \
    .setInputCols(["document", "token", "embeddings"]) \
    .setOutputCol("ner")

# Create a NerConverter for converting the NER results to human-readable format
ner_converter = NerConverter() \
    .setInputCols(["document", "token", "ner"]) \
    .setOutputCol("ner_chunk")

    pipeline = Pipeline(stages=[document_assembler, tokenizer, embeddings, ner, ner_converter])

# Your example data
example = spark.createDataFrame([['১৯৪৮ সালে ইয়াজউদ্দিন আহম্মেদ মুন্সিগঞ্জ উচ্চ বিদ্যালয় থেকে মেট্রিক পাশ করেন এবং ১৯৫০ সালে মুন্সিগঞ্জ হরগঙ্গা কলেজ থেকে ইন্টারমেডিয়েট পাশ করেন']], ["text"])

# Fit the pipeline on the example data
result = pipeline.fit(example).transform(example)

result.show(truncate=False)
