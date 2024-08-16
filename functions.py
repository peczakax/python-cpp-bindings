from datetime import datetime

def compute_days_interval(date1_str, date2_str):
    date1 = datetime.strptime(date1_str, "%Y-%m-%d")
    date2 = datetime.strptime(date2_str, "%Y-%m-%d")
    return abs((date2 - date1).days)

def compute_months_interval(date1_str, date2_str):
    date1 = datetime.strptime(date1_str, "%Y-%m-%d")
    date2 = datetime.strptime(date2_str, "%Y-%m-%d")
    years_diff = date2.year - date1.year
    months_diff = date2.month - date1.month
    return abs(years_diff * 12 + months_diff)

def compute_days_interval_dt(date1, date2):
    return abs((date2 - date1).days)

def compute_months_interval_dt(date1, date2):
    years_diff = date2.year - date1.year
    months_diff = date2.month - date1.month
    return abs(years_diff * 12 + months_diff)
