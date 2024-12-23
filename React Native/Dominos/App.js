import { BasketContext } from './Context';
import StackNavigator from './StackNavigator';
import React from 'react';

export default function App() {
  return (
    <BasketContext>
      <StackNavigator />
    </BasketContext>
  )
}