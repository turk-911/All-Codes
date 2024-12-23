"use client";
import React from 'react'
import { notFound } from 'next/navigation'
function getRandomInt(count: number) {
  return Math.floor(Math.random() * count);
}
export default function page({ params }: {
    params: {
        productId: string,
        reviewId: string
    }
}) {
  if (parseInt(params.reviewId) > 1000) {
    notFound();
  }
  const random = getRandomInt(2);
  if(random == 1) throw new Error("error loading review")
    return (
      <div>
        <p>
          Review number {params.reviewId} for product number {params.productId}{" "}
        </p>
      </div>
    );
}
