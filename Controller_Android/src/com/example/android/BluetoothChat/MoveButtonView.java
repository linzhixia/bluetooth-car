package com.example.android.BluetoothChat;

import android.annotation.SuppressLint;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.view.View;

public class MoveButtonView extends View{
	public MoveButtonView(Context context) {
		super(context);
	}
	public MoveButtonView(Context context,AttributeSet attrs){
	       super(context, attrs);
	}
	@SuppressLint("DrawAllocation")
	public void onDraw(Canvas canvas) {
		Paint mPaint = new Paint();
		mPaint.setColor(Color.GRAY);
		canvas.drawRect(60, 30, 180, 130, mPaint);
		canvas.drawRect(60, 140, 180, 240, mPaint);
		canvas.drawRect(250, 50, 370, 150, mPaint);
		canvas.drawRect(380, 50, 500, 150, mPaint);
		mPaint.setColor(Color.WHITE);
		mPaint.setTextSize(40);
		canvas.drawText("¡ü", 115, 85, mPaint);
		canvas.drawText("¡ý", 115, 185, mPaint);
		canvas.drawText("¡û", 295, 105, mPaint);
		canvas.drawText("¡ú", 415, 105, mPaint);
	} 
}
