package dev.gaudnik.poiji;

import com.poiji.annotation.ExcelCellName;
import com.poiji.annotation.ExcelRow;
import com.poiji.bind.Poiji;

import java.io.File;
import java.util.List;

class InvoiceExel {

	@ExcelRow
	private int rowIndex;

	@ExcelCellName("Name")
	private String name;

	@ExcelCellName("Amount")
	private Double amount;

	@ExcelCellName("Number")
	private String number;

	@ExcelCellName("ReceivedDate")
	private String receivedDate;

	@Override
	public String toString() {
		return "InvoiceExcel [rowIndex=" + rowIndex + ", name=" + name + ", amount=" + amount + ", number=" + number
				+ ", receivedDate=" + receivedDate + "]";
	}

	public static void main(String[] args) {
		File file = new File("poiji/src/main/resources/InvoiceDetailsSheet.xlsx");
		List<InvoiceExel> invoices = Poiji.fromExcel(file, InvoiceExel.class);
		System.out.println("Printing List Data: " + invoices);
	}
}
