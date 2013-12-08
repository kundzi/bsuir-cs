<?php

class Drug
{

  function Drug($name, $prod, $factor, $price)
  {
    $this->name = $name;
    $this->producer = $prod;
    $this->formFactor = $factor;
    $this->price = $price;
  }

  var $name = 'name';
  var $producer = 'somepharm';
  var $formFactor = 'pills';
  var $price = 42;
}

class Delivery
{
  var $date;
  var $drugs;
}

class Order
{
  function  Order($time, $drug, $count)
  {
    $this->time  = $time;
    $this->drugs = $drug;
    $this->count = $count;
   }

  var $time;
  var $drugs;
  var $count;
}

interface iDataSource
{
  public function getDrugs();

  public function addDrug(Drug $drug);

  public function getDeliveries();

  public function getOrders();

  public function addOrder(Order $order);

  public function getRandomComment();

  public function addComment($email, $drug, $comment);
}

class FileDataSource implements iDataSource
{
  private $file_drugs = '_data/drugs.tsv';
  private $file_comments = '_data/comments.tsv';
  private $file_orders = '_data/orders.tsv';


  function FileDataSource()
  {
  }

  public function getDrugs()
  {
    $drugs = array();
    $handle = fopen($this->file_drugs, 'r+');
    if ($handle) {
      while (($line = fgets($handle)) !== false) {
        $line = trim($line);
        if (!empty($line)) {
          $parts = explode("\t", $line);
          $drugs[] = new Drug($parts[0], $parts[1], $parts[2], $parts[3]);
        }
      }
      fclose($handle);
    }
    return $drugs;
  }

  public function addDrug(Drug $drug)
  {
    $handle = fopen($this->file_drugs, 'a');
    if ($handle) {
      $towrite = array($drug->name, $drug->producer, $drug->formFactor, $drug->price);
      fwrite($handle, join("\t", $towrite) . "\n");
    }
    fclose($handle);
  }

  public function getDeliveries()
  {
    // TODO: Implement getDeliveries() method.
  }

  public function getOrders()
  {
    $orders = array();
    $handle = fopen($this->file_orders, 'r+');
    if ($handle) {
      while (($line = fgets($handle)) !== false) {
        if (!empty($line)) {
          $parts = explode("\t", $line);
          $orders[] = new Order($parts[0], $parts[1], $parts[2]);
        }
      }
      fclose($handle);
    }
    return $orders;
  }

  public function addComment($email, $drug, $comment)
  {
    $handle = fopen($this->file_comments, 'a');
    if ($handle) {
      $towrite = array($email, $drug, $comment);
      fwrite($handle, join("\t", $towrite) . "\n");
      fclose($handle);
    }
  }

  public function getRandomComment()
  {
    $handle = fopen($this->file_comments, 'r');
    $comments = array();
    if ($handle) {
      while (($line = fgets($handle)) !== false) {
        if (!empty($line))
          $comments[] = $line;
      }
      fclose($handle);

      if (!empty($comments)) {
        srand();
        $parts = explode("\t", $comments[array_rand($comments)]);
        return "$parts[0]:\n$parts[2]";
      }
    }
    return '';
  }

  public function addOrder(Order $order)
  {
    $handle = fopen($this->file_orders, 'a+');
    if ($handle) {
      $towrite = array($order->time, $order->drugs, $order->count);
      fwrite($handle, join("\t", $towrite) . "\n");
      fclose($handle);
    }
  }
}
