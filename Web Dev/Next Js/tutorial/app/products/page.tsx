import Link from 'next/link'
import React from 'react'

export default function Products() {
  const productId = 100;
  return (
    <div>
        <h1>Products</h1>
        <ul>
            <li><Link href={'products/1'}>Product 1</Link></li>
            <li>product 2</li>
            <li>product 3</li>
        </ul>
        <h2>
          <Link href={`products/${productId}`}>Product {productId}</Link>
        </h2>
    </div>
  )
}
